import numpy as np
import cv2

face_cascade = cv2.CascadeClassifier('C:\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt.xml')
eye_cascade = cv2.CascadeClassifier('C:\\opencv\\build\\etc\\haarcascades\\haarcascade_eye.xml')

font = cv2.FONT_HERSHEY_SIMPLEX

# BGR 제한 값
blue_threshold = 200
green_threshold = 200
red_threshold = 200
bgr_threshold = [blue_threshold, green_threshold, red_threshold]

lower_black = np.array([0, 0, 0])
upper_black = np.array([125, 125, 125])
lower_red = np.array([-10, 100, 100])
upper_red = np.array([10, 255, 255])
lower_white = np.array([130, 130, 130])
upper_white = np.array([255, 255, 255])


def black_detection(frame, hsv):
    mask_black = cv2.inRange(hsv, lower_black, upper_black)
    res = cv2.bitwise_and(frame, frame, mask=mask_black)

    cv2.imshow('Black Detection', res)


def red_detection(frame, hsv):
    mask_red = cv2.inRange(hsv, lower_red, upper_red)
    res = cv2.bitwise_and(frame, frame, mask=mask_red)

    cv2.imshow('Red Detection', res)


def white_detection(frame, hsv):
    mask_white = cv2.inRange(hsv, lower_white, upper_white)
    res = cv2.bitwise_and(frame, frame, mask=mask_white)

    cv2.imshow('White Detection', res)


def face_detection(frame, gray, eye_detection):
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)

    for(x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
        cv2.putText(frame, 'Detected Face', (x - 5, y - 5), font, 0.5, (255, 255, 0), 2)

        if eye_detection:
            roi_gray = gray[y:y + h, x:x + w]
            roi_color = frame[y:y + h, x:x + w]
            eyes = eye_cascade.detectMultiScale(roi_gray)
            for(ex, ey, ew, eh) in eyes:
                cv2.rectangle(roi_color, (ex, ey), (ex + ew, ey + eh), (0, 255, 0), 2)

    if eye_detection:
        info = 'Eye Detection On'
    else:
        info = 'Eye Detection Off'
    cv2.putText(frame, info, (5, 15), font, 0.5, (255, 0, 0), 1)

    cv2.imshow('Face Detection', frame)


def crosswalk_detection(frame, approx, canny):
    approx = np.squeeze(approx)
    x = approx[2][0]
    x2 = approx[0][0]
    x_right_and_bottom = approx[1][0]
    x_left_and_bottom = approx[3][0]
    y = approx[0][1]
    y2 = approx[2][1]

    if ((abs(x2-x) > 150)and(y-y2 > 25)and(x2-x > y-y2)) or ((abs(x-x2) > 150)and(y-y2 > 25)and(x-x2 > y2-y)):
        # print("x의 길이1: ", x_right_and_bottom - x, "x의 길이2: ", x2 - x_left_and_bottom)
        if abs(x_right_and_bottom-x) > 150 and abs(x2-x_left_and_bottom) > 150:
            cv2.drawContours(frame, [approx], -1, (255, 0, 0), 2)
            if x2-x > y-y2:
                cv2.putText(frame, 'Detected First Square', (x - 5, y - 40), font, 0.5, (255, 255, 0), 2)
            else:
                cv2.putText(frame, 'Detected First Square', (x2 - 5, y2 - 20), font, 0.5, (255, 255, 0), 2)
            # print("Detected First Square Edge: ", [approx])

            (_, contours, _) = cv2.findContours(canny.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

            for cnt in contours:
                if cv2.contourArea(cnt) > 50:
                    approx = cv2.approxPolyDP(cnt, 0.01 * cv2.arcLength(cnt, True), True)
                    if len(approx) == 4:  # find rectangle
                        approx = np.squeeze(approx)
                        xx = approx[2][0]
                        xx2 = approx[0][0]
                        yy = approx[0][1]
                        yy2 = approx[2][1]
                        # print("Detected Second Square Edge: ", [approx])

                        if (x != xx) and (x2 != xx2) and (y != yy) and (y2 != yy2):
                            if ((xx >= x) and (xx2 <= x2) and (yy <= y) and (yy2 <= y)) or \
                                    ((xx <= x) and (xx2 >= x2) and (yy <= y) and (yy2 <= y)):

                                if ((abs(xx2-xx) > 100)and(yy-yy2 > 10)and(xx2-xx > yy-yy2)) or\
                                        ((abs(xx-xx2) > 100)and(yy-yy2 > 10)and(xx-xx2 > yy2-yy)):

                                    cv2.drawContours(frame, [approx], -1, (255, 0, 0), 2)
                                    # print("y = ", y, " y2 = ", y2, " yy = ", yy, " yy2 = ", yy2)

                                    if (xx2-xx > yy-yy2) and (yy2-y > 50):
                                        cv2.putText(frame, 'Detected Second Square',
                                                    (xx - 5, yy - 40), font, 0.5, (255, 255, 0), 2)
                                        # print("Detected Square Edge: ", [approx])

                                        approx = np.array([[(xx2, yy), (x_right_and_bottom, y2), (x, y2), (xx, yy)]],
                                                          dtype=np.int32)
                                        cv2.drawContours(frame, [approx], -1, (0, 255, 255), 2)
                                        cv2.putText(frame, 'Detected Crosswalk',
                                                    (xx - 5, yy - 25), font, 0.5, (50, 200, 200), 2)
                                        print("Detected Crosswalk Edge: ", [approx])
                                    elif (xx-xx2 > yy2-yy) and (y-yy2 > 50):
                                        cv2.drawContours(frame, [approx], -1, (255, 0, 0), 2)
                                        cv2.putText(frame, 'Detected Second Square',
                                                    (xx2 - 5, yy2 - 40), font, 0.5, (255, 255, 0), 2)
                                        # print("Detected Square Edge: ", [approx])

                                        approx = np.array([[(xx, yy2), (x_left_and_bottom, y), (x2, y), (xx2, yy2)]],
                                                          dtype=np.int32)
                                        cv2.drawContours(frame, [approx], -1, (0, 255, 255), 2)
                                        cv2.putText(frame, 'Detected Crosswalk',
                                                    (xx2 - 5, yy2 - 25), font, 0.5, (50, 200, 200), 2)
                                        print("Detected Crosswalk Edge: ", [approx])


def edge_tracking(frame, canny):
    (_, contours, _) = cv2.findContours(canny.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    for cnt in contours:
        if cv2.contourArea(cnt) > 400:
            approx = cv2.approxPolyDP(cnt, 0.01 * cv2.arcLength(cnt, True), True)
            if len(approx) == 4:                # find rectangle
                # cv2.drawContours(frame, [approx], -1, (255, 0, 0), 2)
                crosswalk_detection(frame, approx, canny)
                # print("Edge: ", [approx])

    # cv2.imshow('Edge Tracking', frame)


def roi_setting(frame, vertices, color3=(255, 255, 255), color1=255):
    mask = np.zeros_like(frame)                 # 'mask' is empty image of same size with 'frame'

    if len(frame.shape) > 2:                    # color image (Channel 3)
        color = color3
    else:                                       # gray scale image (Channel 1)
        color = color1

    cv2.fillPoly(mask, vertices, color)         # vertices에 정한 점들로 이뤄진 다각형부분(ROI 설정부분)을 color로 채움
    roi_frame = cv2.bitwise_and(frame, mask)    # 이미지와 color로 채워진 ROI를 합침

    return roi_frame


def mark_frame(frame, canny):                          # search for white line
    h, w = frame.shape[:2]                      # 이미지 높이, 너비

    # 사다리꼴 모형의 Points
    vertices = np.array([[(30, h), (w/2-90, h/2-30), (w/2+90, h/2-30), (w-30, h)]], dtype=np.int32)
    roi_frame = roi_setting(frame, vertices, (0, 0, 255))   # vertices에 정한 점들 기준으로 ROI 이미지 생성
    mark = np.copy(roi_frame)                   # copy the 'roi_frame'

    # BGR 제한 값보다 작으면 검은색으로
    thresholds = (frame[:, :, 0] < bgr_threshold[0]) | (frame[:, :, 1] < bgr_threshold[1]) | \
                 (frame[:, :, 2] < bgr_threshold[2])
    mark[thresholds] = [0, 0, 0]

    # 흰색 차선 검출한 부분을 원본 frame에 overlap 하기
    color_thresholds = (mark[:, :, 0] == 0) & (mark[:, :, 1] == 0) & (mark[:, :, 2] > 200)
    frame[color_thresholds] = [0, 0, 255]

    edge_tracking(frame, canny)

    cv2.imshow('Line Detect', frame)


def play_video():
    eye_detection = False

    try:
        cap = cv2.VideoCapture(0)
    except:
        print('Camera loading failed.')
        return

    while True:
        ret, frame = cap.read()
        if not ret:
            break

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        canny = cv2.Canny(gray, 30, 150, apertureSize=3)

        # black_detection(frame, hsv)
        # red_detection(frame, hsv)
        # white_detection(frame, hsv)
        # face_detection(frame, gray, eye_detection)
        # edge_tracking(frame, canny)
        mark_frame(frame, canny)

        k = cv2.waitKey(30)
        if k == ord('e'):
            eye_detection = not eye_detection
        if k == 27:
            break

    cap.release()
    cv2.destroyAllWindows()


play_video()

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

const char* ssid = "DLive_A279";
const char* pass = "D163D2A278";
// const char* ssid = "just";
// const char* pass = "justjust";

IPAddress server_addr(13, 124, 185, 67);
// char* user = "woojae";
// char* password = "YBJ11111";
char* user = "ubuntu";
char* password = NULL;

char* query = "SELECT waiting_num FROM number WHERE date=CURRENT_DATE() AND store_id='1' AND counter_id='2' AND calling_end IS NULL ORDER BY waiting_num ASC limit 1";

WiFiClient client;
MySQL_Connection conn((Client *) & client);
MySQL_Cursor cur = MySQL_Cursor(&conn);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("");
  Serial.println("Connecting to database ...");
}

void loop() {
  while(conn.connect(server_addr, 3306, user, password) != true) {
    delay(500);
    Serial.print(".");
    String url = String("/connect/run.php");
    client.println(String("GET ") + url + " HTTP/1.1\r\n" + "\r\n" + "Connection: close\r\n\r\n");
  }

  row_values *row = NULL;
  long head_count = 0;

  delay(1000);

/*
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  // Execute the query
  cur_mem->execute(query);
  // Fetch the columns (required) but we don't use them.
  column_names *columns = cur_mem->get_columns();

  // Read the row (we are only expecting the one)
  do {
    row = cur_mem->get_next_row();
    if (row != NULL) {
      head_count = atol(row->values[0]);
    }
  } while (row != NULL);
  // Deleting the cursor also frees up memory used
  delete cur_mem;

  // Show the result
  Serial.print("  NYC pop = ");
  Serial.println(head_count);

  delay(500);

   // Execute the query
  cur.execute(query);
  // Fetch the columns (required) but we don't use them.
  cur.get_columns();
  // Read the row (we are only expecting the one)
  do {
    row = cur.get_next_row();
    if (row != NULL) {
      head_count = atol(row->values[0]);
    }
  } while (row != NULL);
  // Now we close the cursor to free any memory
  cur.close();

  // Show the result but this time do some math on it
  Serial.print("  NYC pop = ");
  Serial.println(head_count);
  Serial.print("  NYC pop increased by 12 = ");
  Serial.println(head_count+12);
*/
/*
  while(client.available()) {
    String line = client.readStringUntil('\r'); 
    Serial.print(line);
  }
*/
  Serial.println();
  Serial.println("connection closed");
  delay(30000);
}


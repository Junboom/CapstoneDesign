package com.example.b108.freetime;

import android.content.Context;
import android.support.annotation.Nullable;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.widget.LinearLayout;
import android.widget.TextView;

/**
 * Created by B108 on 2018-04-03.
 */

public class RcntListItemView extends LinearLayout {
    TextView rcntOrder;
    TextView rcntTime;
    public RcntListItemView(Context context) {
        super(context);

        init(context);
    }

    public RcntListItemView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);

        init(context);
    }

    private void init(Context context){
       LayoutInflater inflater=(LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
       inflater.inflate(R.layout.rcnt_list_items,this, true);

       rcntOrder=(TextView) findViewById(R.id.rcntOrder);
       rcntTime=(TextView) findViewById(R.id.rcntTime);
    }

    public void setwOrder(int wOrder ){
        rcntOrder.setText(wOrder);
    }


     public void setwTime(int wTime){
        rcntTime.setText(wTime);
     }





}

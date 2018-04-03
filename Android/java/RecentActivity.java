package com.example.b108.freetime;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class RecentActivity extends AppCompatActivity {





    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_recent);

        ListView listView =findViewById(R.id.listview);

        List<String> list = new ArrayList<>();

        ArrayAdapter<String> adapter = new ArrayAdapter<>
                (this,android.R.layout.simple_list_item_1,list);

        listView.setAdapter(adapter);
        listView.setAdapter(adapter);

        list.add("타로\n"+ "현재 예상 대기시간: 13분");
        list.add("맛나식당\n"+"현재 예상 대기시간: 11분");
        list.add("OO은행\n"+"현재 예상 대기시간: 35분");
        list.add("00서비스센터\n"+"현재 예상 대기시간: 27분");
        list.add("술고래\n"+"현재 예상 대기시간: 7분");


        Button BackMainButton = (Button) findViewById(R.id.BackMainButton);
        BackMainButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });
    }


}
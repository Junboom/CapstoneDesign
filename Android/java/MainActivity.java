package com.example.b108.freetime;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);




       ListView listView =findViewById(R.id.listview);

        List<String> list = new ArrayList<>();

        ArrayAdapter<String> adapter = new ArrayAdapter<>
                (this,android.R.layout.simple_list_item_1,list);

            listView.setAdapter(adapter);
            listView.setAdapter(adapter);

            list.add("사주\n"+"대기번호: 1            " + "예상 대기시간: 5분");
            list.add("토끼정\n"+"대기번호: 3            " + "예상 대기시간: 12분");
            list.add("우리은행\n"+"대기번호: 6            " + "예상 대기시간: 27분");



        Button recentButton = (Button)findViewById(R.id.recentButton);
        recentButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent =
                        new Intent(getApplicationContext(), RecentActivity.class);
                startActivity(intent);
            }
        });

        Button delayButton = (Button) findViewById(R.id.delayButton);
        delayButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                showMessage1();
            }
        });
        Button deleteButton = (Button) findViewById(R.id.deleteButton);
        deleteButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                showMessage2();
            }
        });

        ImageButton AlertButton =(ImageButton) findViewById(R.id.AlertButton);
        AlertButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent =
                            new Intent(getApplicationContext(), AlarmActivity.class);
                    startActivity(intent);
                }
        });
    }



    public void showMessage1() {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("순번 미루기");
        builder.setCancelable(false);
        builder.setMessage("순번을 미루시겠습니까?\n\n");
        builder.setMessage("현재 대기팀   명");


        builder.setPositiveButton("예", new DialogInterface.OnClickListener(){
            @Override
            public void onClick(DialogInterface dialog, int which) {

            }
        });
        builder.setNegativeButton("아니오", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

            }
        });

        AlertDialog dialog = builder.create();
        dialog.show();
    }


    public void showMessage2() {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("대기표 취소");
        builder.setMessage("대기표를 취소하시겠습니까?");
        builder.setIcon(android.R.drawable.ic_delete);

        builder.setPositiveButton("예", new DialogInterface.OnClickListener(){
            @Override
            public void onClick(DialogInterface dialog, int which) {

            }
        });
        builder.setNegativeButton("아니오", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

            }
        });
        AlertDialog dialog = builder.create();
        dialog.show();

    }



}

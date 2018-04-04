package com.example.b108.freetime;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;

/**
 * Created by B108 on 2018-03-28.
 */

public class ListViewAdapter extends BaseAdapter {

    private ArrayList<Waiting> waitList;
    private Context context;

    public ListViewAdapter(ArrayList<Waiting> waitList, Context context) {
        this.waitList = waitList;
        this.context = context;
    }

    @Override
    public int getCount() {
        return waitList.size();
    }

    @Override
    public Object getItem(int position) {
        return waitList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    class Holder{
        private TextView rcntOrder;
        private TextView rcntTime;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        if (convertView == null) {
            convertView = LayoutInflater.from(context).inflate(R.layout.rcnt_list_items, parent, false);
        }

        Holder holder = new Holder();

        holder.rcntOrder = (TextView)convertView.findViewById(R.id.rcntOrder);
        holder.rcntTime = (TextView)convertView.findViewById(R.id.rcntTime);

        holder.rcntOrder.setText(waitList.get(position).getwOrder());
        holder.rcntTime.setText(waitList.get(position).getwTime());


        return convertView;
    }
}

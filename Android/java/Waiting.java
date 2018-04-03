package com.example.b108.freetime;

/**
 * Created by B108 on 2018-03-28.
 */

public class Waiting {
    private int wOrder;
    private int wTime;

    public Waiting(int wOrder, int wTime) {
        this.wOrder = wOrder;
        this.wTime = wTime;
    }

    public int getwOrder() {
        return wOrder;
    }

    public int getwTime() {
        return wTime;
    }

    public void setwOrder(int wOrder) {
        this.wOrder = wOrder;
    }

    public void setwTime(int wTime) {
        this.wTime = wTime;
    }

    @Override
    public String toString() {
        return "Waiting{" +
                "wOrder=" + wOrder +
                ", wTime=" + wTime +
                '}';
    }
}

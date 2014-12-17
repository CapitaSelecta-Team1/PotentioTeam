package Backend;

import static java.lang.Thread.sleep;

public class TimerThread implements Runnable {

	private Gui g;
	private int amount;
	
	public TimerThread(Gui g, int amount) {
		this.g = g;
		this.amount = amount;
	}
	
    public void run() {
        int i = amount;
        g.CounterStatusValue.setText(String.valueOf(i));
        while(i > 0) {
            try {
                sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            g.CounterStatusValue.setText(String.valueOf(i-1));
            i--;
        }
        g.activateAlarm();
    }
}
package Backend;
//package backend;
//
//import static java.lang.Thread.sleep;
//
//import java.awt.Color;
//
//public class ButtonThread implements Runnable {
//
//	private Gui g;
//	
//	public ButtonThread(Gui g) {
//		this.g = g;
//	}
//	
//    public void run() {
//    	g.ButtonStatusColor.setBackground(Color.GREEN);
//        try {
//            sleep(1000);
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }
//        g.ButtonStatusColor.setBackground(Color.RED);
//    }
//}
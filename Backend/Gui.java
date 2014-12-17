package Backend;

import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 * Created by koencertyn on 11/12/14.
 */
public class Gui extends JFrame{

    public static final int EXIT_BUTTONS_X = 200;
    public static final int EXIT_BUTTONS_Y = 200;
    public static final int EXIT_BUTTONS_SIZE_X = 80;
    public static final int EXIT_BUTTONS_SIZE_Y = 40;

    public static final int GLOBAL_STATUS_X = 5;
    public static final int GLOBAL_STATUS_Y = 5;

    public static final int GLOBAL_STATUS_SIZE_X = 200;
    public static final int GLOBAL_STATUS_SIZE_Y = 40;

    public static final int GLOBAL_COLOR_SIZE_X = 100;
    public static final int GLOBAL_COLOR_SIZE_Y = 40;
    
    public static final int TIMERDURATION = 20;

    public JLabel CounterStatusValue, alarmStatusColor, IRStatusColor;
    
    private Thread timerThread;
    
    private boolean alarmTotallyDisabled = false;
    private boolean timerThreadActive = false;

    private AlarmComp comp;
    public Gui(AlarmComp comp) {
    	this.comp = comp;
        initGui();
        
    }

    private void initGui(){
        setTitle("Alarm Status");
        setSize(380,350);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);

        Container pane = getContentPane();
        GroupLayout layout = new GroupLayout(pane);
        pane.setLayout(layout);

        JButton offButton = new JButton("Off");
        offButton.setLayout(null);
        offButton.setLocation(EXIT_BUTTONS_X,  EXIT_BUTTONS_Y + 60);
        offButton.setSize(EXIT_BUTTONS_SIZE_X - 10, EXIT_BUTTONS_SIZE_Y);
        offButton.setHorizontalAlignment(0);
        offButton.setForeground(Color.black);
        add(offButton);
        
        JButton onButton = new JButton("On");
        onButton.setLayout(null);
        onButton.setLocation(EXIT_BUTTONS_X + EXIT_BUTTONS_SIZE_X + 10,  EXIT_BUTTONS_Y + 60);
        onButton.setSize(EXIT_BUTTONS_SIZE_X - 10, EXIT_BUTTONS_SIZE_Y);
        onButton.setHorizontalAlignment(0);
        onButton.setForeground(Color.black);
        add(onButton);

        JButton resetButton = new JButton("Reset");
        resetButton.setLayout(null);
        resetButton.setLocation(EXIT_BUTTONS_X, EXIT_BUTTONS_Y);
        resetButton.setSize(EXIT_BUTTONS_SIZE_X*2, EXIT_BUTTONS_SIZE_Y);
        resetButton.setHorizontalAlignment(0);
        resetButton.setForeground(Color.black);
        add(resetButton);

        JButton testButton = new JButton("Detect movement");
        testButton.setLayout(null);
        testButton.setLocation(EXIT_BUTTONS_X - EXIT_BUTTONS_SIZE_X*2 - 20 , EXIT_BUTTONS_Y);
        testButton.setSize(EXIT_BUTTONS_SIZE_X*2, EXIT_BUTTONS_SIZE_Y);
        testButton.setHorizontalAlignment(0);
        testButton.setForeground(Color.black);
        add(testButton);

        JButton deactivateButton = new JButton("Deactivate alarm");
        deactivateButton.setLayout(null);
        deactivateButton.setLocation(EXIT_BUTTONS_X - EXIT_BUTTONS_SIZE_X*2 - 20 , EXIT_BUTTONS_Y + 60);
        deactivateButton.setSize(EXIT_BUTTONS_SIZE_X*2, EXIT_BUTTONS_SIZE_Y);
        deactivateButton.setHorizontalAlignment(0);
        deactivateButton.setForeground(Color.black);
        add(deactivateButton);

        resetButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	resetAlarm();
            }
        });

        offButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	System.out.println("sending off to alarm");
            	comp.changeAlarmStatus(new Byte("00000000"));
            }
        });
        
        onButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	System.out.println("sending on to alarm");
            	comp.changeAlarmStatus(new Byte("00000001"));
            }
        });

        testButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	activateMovement();
            }
        });

        deactivateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	deactivateAlarm();
            }
        });

        JLabel alarmStatusText = new JLabel("The current alarm status :");
        alarmStatusText.setLayout(null);
        alarmStatusText.setLocation(GLOBAL_STATUS_X, GLOBAL_STATUS_Y);
        alarmStatusText.setSize(GLOBAL_STATUS_SIZE_X, GLOBAL_STATUS_SIZE_Y);
        alarmStatusText.setHorizontalAlignment(0);
        alarmStatusText.setForeground(Color.black);
        add(alarmStatusText);

        alarmStatusColor = new JLabel("Standby");
        alarmStatusColor.setOpaque(true);
        alarmStatusColor.setLocation(GLOBAL_STATUS_X + GLOBAL_STATUS_SIZE_X + 20, GLOBAL_STATUS_Y);
        alarmStatusColor.setSize(GLOBAL_COLOR_SIZE_X, GLOBAL_COLOR_SIZE_Y);
        alarmStatusColor.setHorizontalAlignment(0);
        alarmStatusColor.setBackground(Color.ORANGE);
        add(alarmStatusColor);

        JLabel IRStatusText = new JLabel("Movement in room :");
        IRStatusText.setLayout(null);
        IRStatusText.setLocation(GLOBAL_STATUS_X, GLOBAL_STATUS_Y + GLOBAL_STATUS_SIZE_Y + 20);
        IRStatusText.setSize(GLOBAL_STATUS_SIZE_X, GLOBAL_STATUS_SIZE_Y);
        IRStatusText.setHorizontalAlignment(0);
        IRStatusText.setForeground(Color.black);
        add(IRStatusText);

        IRStatusColor = new JLabel("Detecting");
        IRStatusColor.setOpaque(true);
        IRStatusColor.setLocation(GLOBAL_STATUS_X + GLOBAL_STATUS_SIZE_X + 20, GLOBAL_STATUS_Y + GLOBAL_STATUS_SIZE_Y + 20);
        IRStatusColor.setSize(GLOBAL_COLOR_SIZE_X, GLOBAL_COLOR_SIZE_Y);
        IRStatusColor.setHorizontalAlignment(0);
        IRStatusColor.setBackground(Color.ORANGE);
        add(IRStatusColor);

        JLabel CounterStatusText = new JLabel("Counter :");
        CounterStatusText.setLayout(null);
        CounterStatusText.setLocation(GLOBAL_STATUS_X, GLOBAL_STATUS_Y + 2*(GLOBAL_STATUS_SIZE_Y + 20));
        CounterStatusText.setSize(GLOBAL_STATUS_SIZE_X, GLOBAL_STATUS_SIZE_Y);
        CounterStatusText.setHorizontalAlignment(0);
        CounterStatusText.setForeground(Color.black);
        add(CounterStatusText);

        CounterStatusValue = new JLabel(String.valueOf("--"));
        CounterStatusValue.setFont(new Font("Serif", Font.PLAIN, 40));
        CounterStatusValue.setOpaque(true);
        CounterStatusValue.setLocation(GLOBAL_STATUS_X + GLOBAL_STATUS_SIZE_X + 20, GLOBAL_STATUS_Y + 2* (GLOBAL_STATUS_SIZE_Y + 20));
        CounterStatusValue.setSize(GLOBAL_COLOR_SIZE_X, GLOBAL_COLOR_SIZE_Y);
        CounterStatusValue.setHorizontalAlignment(0);
        add(CounterStatusValue);
    }
    
    public void activateAlarm() {
    	if(!alarmTotallyDisabled) {
    		alarmStatusColor.setBackground(Color.RED);
    		alarmStatusColor.setText("Activated");
    	}
    	comp.changeAlarmStatus(new Byte("00000001"));
    }

    public void deactivateAlarm() {
    	alarmTotallyDisabled = true;
    	if(timerThread != null) {
    		timerThread.stop();
    		timerThreadActive = false;
    	}
        alarmStatusColor.setBackground(Color.GREEN);
        alarmStatusColor.setText("Deactivated");
        IRStatusColor.setBackground(Color.GREEN);
        IRStatusColor.setText("Disabled");
    	CounterStatusValue.setText("--");
    	comp.changeAlarmStatus(new Byte("00000000"));
    	comp.resetReceived();
    }
    
    public void resetAlarm() {
    	alarmTotallyDisabled = false;
    	if(timerThread != null) {
    		timerThread.stop();
    		timerThreadActive = false;
    	}
        alarmStatusColor.setBackground(Color.ORANGE);
        alarmStatusColor.setText("Standby");
        IRStatusColor.setBackground(Color.ORANGE);
        IRStatusColor.setText("Detecting");
    	CounterStatusValue.setText("--");
    	comp.changeAlarmStatus(new Byte("00000000"));
    	comp.resetReceived();
    }

    public void activateMovement(){
    	if(!alarmTotallyDisabled && !timerThreadActive) {
            IRStatusColor.setBackground(Color.RED);
            IRStatusColor.setText("Movement");
        	timerThread = new Thread(new TimerThread(this, TIMERDURATION));
        	timerThread.start();
    		timerThreadActive = true;
    	}
    }
}
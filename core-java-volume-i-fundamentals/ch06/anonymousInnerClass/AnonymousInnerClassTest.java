package anonymousInnerClass;

import java.awt.Toolkit;
import java.awt.event.*;
import java.util.Date;

import javax.swing.JOptionPane;
import javax.swing.Timer;

public class AnonymousInnerClassTest {

    public static void main(String[] args) {
        
        TalkingClock clock = new TalkingClock();
        clock.start(1000, false);

        JOptionPane.showMessageDialog(null, "Quit program?");

        System.exit(0);
    }
}


class TalkingClock {

    public void start(int interval, boolean beep) {

        ActionListener listener = new ActionListener() {

            public void actionPerformed(ActionEvent event) {
                System.out.println("At the tone, the time is " + new Date());
                if (beep) Toolkit.getDefaultToolkit().beep();
            }
        };

        Timer t = new Timer(interval, listener);
        t.start();
    }
}
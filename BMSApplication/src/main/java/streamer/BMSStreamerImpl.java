package streamer;

import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.ThreadLocalRandom;

/*
 * This method will print 2 random values(separated by comma) for every 1 second
 * up to 10 seconds
 */
public class BMSStreamerImpl implements IBMSStreamer {

	public void streamData() {
		final Timer timer = new Timer();

		timer.schedule(new TimerTask() {

			private int count = 0;

			@Override
			public void run() {
				count++;
				if (count > 10) {
					timer.cancel();
					timer.purge();
					return;
				}
				printBatteryValues();

			}

		}, 1000, 1000);
	}

	public void printBatteryValues() {
		StringBuilder bmsValues = new StringBuilder();
		bmsValues.append("batteryTemperature:" + ThreadLocalRandom.current().nextInt(0, 45 + 1));
		bmsValues.append(",");
		bmsValues.append("batterySoC:" + ThreadLocalRandom.current().nextInt(0, 100 + 1));
		System.out.println(bmsValues.toString());
		
		PrintStream o = new PrintStream(new File("Trial.txt"));
		System.setOut(o);
	}

}

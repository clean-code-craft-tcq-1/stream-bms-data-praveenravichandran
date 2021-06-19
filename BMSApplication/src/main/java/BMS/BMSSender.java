package BMS;

import streamer.BMSStreamerImpl;
import streamer.IBMSStreamer;

/**
 * BMS Application that will stream BMS data test
 *
 */
public class BMSSender {
	public static void main(String[] args) {
		IBMSStreamer bmsStreamer = new BMSStreamerImpl();
		bmsStreamer.streamData();
	}
}

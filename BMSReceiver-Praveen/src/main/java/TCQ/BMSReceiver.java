package TCQ;

import receiver.BMSReceiverImpl;
import receiver.IBMSReceiver;

/**
 * Receiver Code!
 *
 */
public class BMSReceiver {
	public static void main(String[] args) throws Exception {
		IBMSReceiver bmsReceiver = new BMSReceiverImpl();
		bmsReceiver.receiveData();
	}
}

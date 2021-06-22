package TCQ;

import static org.junit.Assert.assertEquals;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.mockito.runners.MockitoJUnitRunner;

import receiver.BMSReceiverImpl;
import receiver.IBMSReceiver;

@RunWith(MockitoJUnitRunner.class)
public class BMSReceiverTest {

	@Test
	public void checkIfBMSValuesPrinting() throws Exception {
		IBMSReceiver bmsReceiverImplMock = Mockito.mock(BMSReceiverImpl.class);
		((BMSReceiverImpl) Mockito.doNothing().when(bmsReceiverImplMock)).receiveData();
		bmsReceiverImplMock.receiveData();
		Mockito.verify(bmsReceiverImplMock, Mockito.times(1)).receiveData();
	}

	@Test
	public void checkMaxValue() {
		BMSReceiverImpl bmsReceiverImpl = new BMSReceiverImpl();
		int[] arr = new int[] { 10, 36, 25, 15, 4 };
		assertEquals(36, bmsReceiverImpl.maxNumberOfAnArray(arr));
	}

	@Test
	public void checkMinValue() {
		BMSReceiverImpl bmsReceiverImpl = new BMSReceiverImpl();
		int[] arr = new int[] { 10, 36, 25, 15, 4 };
		assertEquals(4, bmsReceiverImpl.minNumberOfAnArray(arr));
	}

	@Test
	public void checkAverageValue() {
		BMSReceiverImpl bmsReceiverImpl = new BMSReceiverImpl();
		int[] arr = new int[] { 10, 36, 25, 15, 4 };
		assertEquals(18.0, bmsReceiverImpl.movingAverageOfAnArray(arr), 0.2);
	}
}
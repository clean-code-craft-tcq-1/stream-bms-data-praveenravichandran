package BMS;

import java.util.Timer;
import java.util.TimerTask;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.Mockito;
import org.mockito.runners.MockitoJUnitRunner;

import streamer.BMSStreamerImpl;
import streamer.IBMSStreamer;

@RunWith(MockitoJUnitRunner.class)
public class BMSStreamerTest {

	@Mock
	Timer mockedTimer;

	@Test
	public void checkIfBMSValuesPrinting() {
		IBMSStreamer bmsStreamerImplMock = Mockito.mock(BMSStreamerImpl.class);
		((BMSStreamerImpl) Mockito.doNothing().when(bmsStreamerImplMock)).streamData();
		bmsStreamerImplMock.streamData();
		Mockito.verify(mockedTimer).schedule((TimerTask) Mockito.any(), 1000, 1000);
		((BMSStreamerImpl) Mockito.verify(bmsStreamerImplMock, Mockito.times(1))).streamData();
		((BMSStreamerImpl) Mockito.verify(bmsStreamerImplMock, Mockito.times(10))).printBatteryValues();
	}

}

package receiver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BMSReceiverImpl implements IBMSReceiver {

	@Override
	public void receiveData() throws Exception {
		BufferedReader inputReader = new BufferedReader(new InputStreamReader(System.in));
		String input;
		List<String> receivedDataList = new ArrayList<>();

		try {
			while ((input = inputReader.readLine()) != null) {
				System.out.println(input);
				receivedDataList.add(input);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		dataAnalysis(convertInputToIntArray(receivedDataList, 0), "Battery Temperature");
		dataAnalysis(convertInputToIntArray(receivedDataList, 1), "Battery SoC");
	}

	public void dataAnalysis(int[] receivedInputArr, String type) throws Exception {
		Arrays.sort(receivedInputArr);
		printToConsole(minNumberOfAnArray(receivedInputArr), maxNumberOfAnArray(receivedInputArr),
				movingAverageOfAnArray(receivedInputArr), type);
	}

	public int maxNumberOfAnArray(int[] arr) {
		Arrays.sort(arr);
		return arr[arr.length - 1];
	}

	public int minNumberOfAnArray(int[] arr) {
		Arrays.sort(arr);
		return arr[0];
	}

	public float movingAverageOfAnArray(int[] arr) {
		int sum = Arrays.stream(arr).sum();
		return (sum / arr.length);
	}

	public void printToConsole(int minNumber, int maxNumber, float movingAverage, String type) {
		System.out.println("Min " + type + " : " + minNumber);
		System.out.println("Max " + type + " : " + maxNumber);
		System.out.println("Moving average of " + type + " : " + movingAverage);

	}

	public int[] convertInputToIntArray(List<String> inputData, int paramType) {
		int[] arr = new int[inputData.size()];
		int i = 0;
		for (String temperatureData : inputData) {
			arr[i] = Integer.parseInt(temperatureData.split(",")[paramType].split(":")[1]);
		}
		return arr;
	}

}
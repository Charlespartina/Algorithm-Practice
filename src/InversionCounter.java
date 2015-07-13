import java.io.File;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;


public class InversionCounter {
	
	
	/**
	 * Using Merge Sort to count inversions
	 * @param array
	 * @return
	 */
	public static <E extends Comparable<E>> long MergeCounter(E[] array) {
		return CounterHelper(array, 0, array.length - 1);
		
	}
	
	public static <E extends Comparable<E>> long CounterHelper(E[] array, int first, int last) {
		if(first == last){
			return 0;
		}
		int mid = (first + last)/2;
		long x = CounterHelper(array, first, mid);
		long y = CounterHelper(array, mid+1, last);
		long z = CounterMerge(array, first, mid, mid+1, last);
		return x + y + z;
	}
	
	@SuppressWarnings("unchecked")
	public static <E extends Comparable<E>> long CounterMerge(E[] array, int leftfirst, int leftlast, int rightfirst, int rightlast){
		E[] tempList = (E[]) Array.newInstance(array.getClass()
				.getComponentType(), rightlast - leftfirst + 1);
		int tempPointer = 0;
		int leftPointer = leftfirst;
		int rightPointer = rightfirst;
		int tempCounter = 0;
		
		while (leftPointer <= leftlast && rightPointer <= rightlast){
			if (array[leftPointer].compareTo(array[rightPointer]) <= 0 ){
				tempList[tempPointer] = array[leftPointer];
				leftPointer++;
				tempPointer++;
			}
			else{
				// Count how many inversions
				tempList[tempPointer] = array[rightPointer];
				rightPointer++;
				tempPointer++;
				tempCounter += leftlast + 1 - leftPointer;
			}
		
		}
		while (leftPointer <= leftlast){
			tempList[tempPointer] = array[leftPointer];
			leftPointer++;
			tempPointer++;
		}
		while (rightPointer <= rightlast){
			tempList[tempPointer] = array[rightPointer];
			rightPointer++;
			tempPointer++;
		}
		for (int i = 0; i < tempList.length; i++){
			array[leftfirst + i] = tempList[i];
		}
		return tempCounter;
		
	}
	
	public static <E extends Comparable<E>> long BruteForceCounter(E[] array){
		long counter = 0;
		for (int i = 0; i < array.length; i++){
			for (int j = i + 1; j < array.length; j++){
				if (array[i].compareTo(array[j]) > 0){
					
					counter++;
				}
			}
		}
		return counter;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		ArrayList<Integer> prearray = new ArrayList<Integer>();
		
		try {
			File fileinput = new File(args[0]);
			Scanner fileScanner = new Scanner(fileinput);
			while(fileScanner.hasNext()){
				int next = fileScanner.nextInt();
				prearray.add(next);
				//System.out.println(next);
				
			}
			fileScanner.close();
			
		}
		catch(Exception e){
			System.out.println("ERROR");
			e.printStackTrace();
		}
		
		Integer[] array = new Integer[prearray.size()];
		System.out.println(prearray.size());
		System.out.println(array.length);
		
		for (int i = 0; i < prearray.size(); i++){
			array[i] = prearray.get(i);
		}
		
		long bfcounter = BruteForceCounter(array);
		
		
		long mcounter = MergeCounter(array);
		for (int i = 0; i < array.length; i++){
			System.out.println(array[i]);
		}
		System.out.println("The counter for merge is " + mcounter);
		System.out.println("The counter for brute force is "+ bfcounter);

	}
	

}

import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * This program serves to implement QuickSort on a certain array, and count the amount of comparisons between elements when choosing different kinds of pivots.
 * @author Tang
 *
 */
public class QuickSortBenchmark {
	
	public static long MyQuickSort(int[] array){
		return QuickSortFirst(array, 0, array.length - 1);
	}
	public static long QuickSortFirst(int[] array, int first, int last){
		if (first >= last){
			return 0;
		}
		int compareCounter = 0;
		int pivot = choosePivot(array, first, last);
		swap(array, pivot, first);
		int index = partition(array, first, last);
		compareCounter = last - first;
		return compareCounter + QuickSortFirst(array, first, index-1) + QuickSortFirst(array, index+1, last); 
	}
	public static int choosePivot(int[] array, int first, int last){
//		// First Element
//		return first;
		
//		// Last Element;
//		return last;
		
		// The Median of first, last, and middle element
		int medianIndex = 0;
		int middleIndex = (int)Math.floor((last - first)/2) + first;
		
		if (array[first] > array[middleIndex]){
			if(array[first] < array[last]){
				medianIndex = first;
			}
			else{ 
				if(array[last] > array[middleIndex]){
					medianIndex = last;
				}
				else{
					medianIndex = middleIndex;
				}
			}
			
		}else{
			if(array[middleIndex] < array[last]){
				medianIndex = middleIndex;
			}
			else{
				if(array[first] < array[last]){
					medianIndex = last;
				}
				else{
					medianIndex = first;
				}
			}
		}
		
		return medianIndex;
		
	}
	public static int partition(int[] array, int first, int last){
		
		int i = first + 1;
		for (int j = first + 1; j <= last; j++){
			if (array[j] <= array[first]){
				swap(array, i, j);
				i++;
			}
		}
		swap(array, first, i-1);
		
		return i-1;
	}
	public static void swap(int[] array, int a, int b){
		int temp = array[a];
		array[a] = array[b];
		array[b] = temp;
	}
	public static void main(String[] args) {
		ArrayList<Integer> prearray = new ArrayList<Integer>();
		try {
			File fileinput = new File(args[0]);
			Scanner fileScanner = new Scanner(fileinput);
			while(fileScanner.hasNext()){
				int next = fileScanner.nextInt();
				prearray.add(next);
			}
			fileScanner.close();
			
		}
		catch(Exception e){
			System.out.println("ERROR");
			e.printStackTrace();
		}
		
		int[] array = new int[prearray.size()];
		
		for (int i = 0; i < prearray.size(); i++){
			array[i] = prearray.get(i);
		}
		
        int[] test = {5,4,6,1,2,3,7,9,10,8};
        //printArray(test);
        long counter = MyQuickSort(array);
        printArray(array);
        System.out.println("There are " + counter + " comparisons.");
        
	}
	public static void printArray(int[] array){
		for (int i = 0; i < array.length; i++){
			System.out.println(array[i]);
		}
		System.out.println(' ');
		
	}
	

}

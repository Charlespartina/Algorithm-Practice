import java.awt.List;
import java.io.File;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Hashtable;
import java.util.Scanner;
import java.util.Stack;

/** 
 *  The algorithm computes strongly connected components (SCCs) of a given graph.
 *  @author Tang
 */

public class KosarajuAlgorithm {
	
	// The number of vertices
	final static int num = 875714;
	
	private class Vertex{
		int label = 0;
		boolean explored;
		ArrayList<Integer> next;
		ArrayList<Integer> before;
		int leader;
		public Vertex(int label){
			this.label = label;
			this.next = new ArrayList<Integer>();
			this.before = new ArrayList<Integer>();
			this.explored = false;
			leader = 0;
		}
		@SuppressWarnings("unused")
		public Vertex(int label, ArrayList<Integer> next, ArrayList<Integer> before){
			this.label = label;
			this.next = next;
			this.before = before;
			this.explored = false;
			leader = 0;
		}
		public void MarkAsExplored(){
			this.explored = true;
		}
		public void MarkAsUnexplored(){
			this.explored = false;
		}
		public boolean CheckExplored(){
			return explored;
		}
		public void setLeader(int leader){
			this.leader = leader;
		}
	}
	
	/**
	 * This method push all vertices into a stack according to their finishing time. 
	 * @param rev_vertices
	 * @return
	 */
	public static Stack<Integer> FirstPass(Vertex[] rev_vertices){
		Stack<Integer> order = new Stack<Integer>();
		for (int i = rev_vertices.length - 1; i >= 1; i--){
			if (rev_vertices[i].CheckExplored() == false){
				FirstDepthFirstSearch(rev_vertices, rev_vertices[i], order);
				
			}
		}
		return order;
	}
	public static void FirstDepthFirstSearch(Vertex[] vertices, Vertex startVertex, Stack<Integer> order){
		startVertex.MarkAsExplored();
		for (int i = 0; i < startVertex.next.size(); i++){
			if (vertices[startVertex.next.get(i)].CheckExplored() == false){
				FirstDepthFirstSearch(vertices, vertices[startVertex.next.get(i)], order);
			}	
		}
		order.push(startVertex.label);	
	}
	public static ArrayList<Integer> SecondPass(Vertex[] vertices, Stack<Integer> order){
		
		ArrayList<Integer> tmpList;
		Hashtable<Integer, Integer> counter = new Hashtable<Integer, Integer>();
		while(!order.empty()){
			int tmp = order.pop();
			if (vertices[tmp].CheckExplored() == false){
				int tmpLeader = tmp;
				SecondDepthFirstSearch(vertices, vertices[tmp], tmpLeader, counter);
			}
			
		}
		tmpList = new ArrayList<Integer>(counter.values());
		
		return tmpList;
	}
	public static void SecondDepthFirstSearch(Vertex[] vertices, Vertex startVertex, int leader, Hashtable<Integer, Integer> counter){
		startVertex.MarkAsExplored();
		startVertex.setLeader(leader);
		for (int i = 0; i < startVertex.next.size(); i++){
			if(vertices[startVertex.next.get(i)].CheckExplored() == false){
				SecondDepthFirstSearch(vertices, vertices[startVertex.next.get(i)], leader, counter);
			}
		}
		if(counter.containsKey(leader)){
			counter.put(leader, counter.get(leader) + 1);
		}
		else{
			counter.put(leader, 1);
		}
	}
	
	public static ArrayList<Integer> findMaximum(ArrayList<Integer> list, int num){
		Collections.sort(list);
		return list;
	}
	public static void main(String args[]){
		KosarajuAlgorithm a = new KosarajuAlgorithm();
		
		// Initialize the graphs
		Vertex[] vertices = new Vertex[num + 1];
		Vertex[] rev_vertices = new Vertex[num + 1];
		
		vertices[0] = rev_vertices[0] = null;
		for (int i = 1; i <= num; i++){
			vertices[i] = a.new Vertex(i);
			rev_vertices[i] = a.new Vertex(i);
		}
		try {
			
			File fileinput = new File(args[0]);
			Scanner fileScanner = new Scanner(fileinput);
			while(fileScanner.hasNext()){
				String line = fileScanner.nextLine();
				String[] chars = line.split("\\s+");
				for (int i = 0; i < chars.length; i++){
					if (i == 0){
						// Add next element to a vertex
						vertices[Integer.parseInt(chars[i])].next.add(Integer.parseInt(chars[i + 1]));
						rev_vertices[Integer.parseInt(chars[i])].before.add(Integer.parseInt(chars[i + 1]));
					}else{
						vertices[Integer.parseInt(chars[i])].before.add(Integer.parseInt(chars[i - 1]));
						rev_vertices[Integer.parseInt(chars[i])].next.add(Integer.parseInt(chars[i - 1]));
					}
					
				}
				
			}
			fileScanner.close();
			System.out.println("Terminated");
		}
		catch(Exception e){
			System.err.println("ERROR");
			e.printStackTrace();
		}
		
		Stack<Integer> order = FirstPass(rev_vertices);
		ArrayList<Integer> leaderSizes = SecondPass(vertices, order);
		ArrayList<Integer> result = findMaximum(leaderSizes, 5);
		for (int i = 0; i < result.size(); i++){
			System.out.println(result.get(i));
		}
//		while (!order.empty()){
//			System.out.println(order.pop());
//		}
		
		
	}
}

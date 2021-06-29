import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main {
	
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		BST bst = new BST();
		int[] input = new int[100005];
		int k = 0;
		TreeNode root = null;
		try {
			while(scanner.hasNextInt())
			{
				Integer integer = scanner.nextInt();
				input[k++] = integer;
				root = bst.insert(integer, root);
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		finally {	
			for(int i=0;i<k;i++)
			{
				int val = bst.update(input[i], root);
				if(val != -1)
				System.out.println(input[i] +" "+ val);
			}
			
		}
	}

}

class BST {
	
	
	public int update(int val, TreeNode root)
	{
		if(root == null) return -1;
		if(root.data == val)
		{
			int temp = root.freq;
			root.freq = -1;
			return temp;
		}
		else if(root.data > val)
			return update(val,root.leftChild);
		else return update(val, root.rightChild);
	}
	
	public TreeNode insert(int val, TreeNode root)
	{
		TreeNode newNode = new TreeNode(val);
		if(root == null)
		{
			root = newNode;
			return root;
		}
		
		if(val < root.data)
			 root.leftChild = insert(val,root.leftChild);
		else if(val > root.data) root.rightChild = insert(val, root.rightChild);
		else root.freq = root.freq + 1;
		
		return root;
	}
	
}

class TreeNode {
	int data;
	TreeNode leftChild;
	TreeNode rightChild;
	int freq;
	
	public TreeNode(int data) {
		this.data = data;
		this.freq = 1;
	}
}

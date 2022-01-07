
import java.util.*;

public class Programming_lab_05 
{
	
	private static void increase(Buff buff)
	{
		buff.setValue(buff.getValue() + 1);
	}
		
	public static void main(String[] args)
	{
		try
		{
			BatchOfGoods batch = new BatchOfGoods();
			batch.setPrice(-200);
		}
		catch(IllegalArgumentException e)
		{
			System.out.print(e.getMessage() + '\n');
		}
	}
}

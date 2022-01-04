
import java.util.*;
import java.text.*;

public class BatchOfGoods
{
	private String name_;
	private int ID_;
	private float price_;
	private int quantity_;
	private Date date_;
	private SimpleDateFormat date_format_;
	
	public BatchOfGoods()
	{
		name_ = "";
		ID_ = 0;
		price_ = 0;
		quantity_ = 0;
		date_ = null;
		date_format_ = new SimpleDateFormat("dd.MM.yyyy");
	}
	
	public String getName() {return name_;}
	public int getID() {return ID_;}
	public float getPrice() {return price_;}
	public int getQuantity() {return quantity_;} 
	public Date getDate() {return date_;}
	
	public void setName(String name)
	{
		name_ = name;
	}
	
	public boolean setID(int id)
	{
		if(Math.log10(id) < 8)
		{
			ID_ = id;
			return true;
		}
		else return false;
	}
	
	public boolean setPrice(float price)
	{
		if(price > 0)
		{
			price_ = price;
			return true;
		}
		else return false;
	}
	public boolean setQuantity(int quantity)
	{
		if(quantity > 0)
		{
			quantity_ = quantity;
			return true;
		}
		else return false;
	}
	public void setDate(Date date)
	{
		date_ = date;
	}
	public void setDate(String str)
	{
		String[] s = str.split("\\.");
		
	
		
		double double_date = 0;
		
		double_date += (Integer.parseInt(s[2]) - 1970) * 31536000;
		double_date += Integer.parseInt(s[1]) * 31536000 /12;
		double_date += Integer.parseInt(s[0]) * 86400;
		
		long date = (long)(double_date * 1000);
		
		date_ = new Date(date);
	}
	public BatchOfGoods Clone()
	{
		BatchOfGoods batch = new BatchOfGoods();
		
		batch.setName(String.copyValueOf(name_.toCharArray()));
		batch.setID(ID_);
		batch.setPrice(price_);
		batch.setQuantity(quantity_);
		batch.setDate(date_);
		
		return batch;
	}
	public float sellBatchOfGoods(int[] quantity)
	{
		float ret;
		
		if(quantity_ > quantity[0])
		{
			ret = quantity[0] * price_;
            quantity_ -= quantity[0];
            quantity[0] = 0;
		}
		else
		{
			ret = quantity_ * price_;
            quantity[0] -= quantity_;
            quantity_ = 0;
		}
		return ret;		
	}
	public String getBatchAsStringWithoutName()
	{
		String str = "";
		
		str += "\n   | ID: ";
		
		int n = (int)Math.log10(ID_);
		
		for(; n < 7; n++) str += "0";
		
		str += ID_;
		
		str += String.format("\n   | Price: %f", price_);
		str += String.format("\n   | Quantity: %d", quantity_);
		str += String.format("\n   | Date: %s\n   ", date_format_.format(date_));
		
		for (int i = 0; i < 18; i++) str += "-";
		return str;
	}
}

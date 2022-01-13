package test1;

class Vehicle
{
	void go()
	{
		System.out.println("V");
	}
}

class Car extends Vehicle
{
	void go()
	{
		System.out.println("C");
	}
}


public class test3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Car c= new Car();
		c.go();
		Vehicle v = new Vehicle();
		v.go();
		v = c;
		v.go();
		

	}

}

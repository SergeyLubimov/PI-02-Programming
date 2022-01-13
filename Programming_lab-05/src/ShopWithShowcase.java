
public class ShopWithShowcase extends Shop
{
	private int showcase_level_;

	@Override
    public String toString()
	{
		String str = String.format("\n\n*** %s ***\n|cash: %f\n%s", getName(), cash_,
				super.getWarehouse().getPackagesAsString());
        return str;
    }
	
	public ShopWithShowcase()
	{
		super();
		showcase_level_ = 0;
	}

	public ShopWithShowcase(int showcase_level)
	{
		super();
		showcase_level_ = showcase_level;
	}

	public boolean investInShowcase(float investment_amount)
	{
		if (cash_ >= investment_amount && investment_amount > 0)
		{
			cash_ -= investment_amount;
			showcase_level_ = (int)(showcase_level_ / 10 + (investment_amount / 1000) + Math.log10(investment_amount));
			return true;
		}
		return false;
	}

	public int getShowcaseLevel()
	{
		return showcase_level_;
	}

	public void setMargin(int percent)
	{
		margin_ = 1 + ((float)(percent) + showcase_level_) / 100;
	}

	/*public void setMargin(unsigned percent)
	{
		Shop::setMargin(percent + showcase_level_);
	}*/
}

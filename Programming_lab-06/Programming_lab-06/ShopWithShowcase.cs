using System;
using System.Collections.Generic;
using System.Text;

namespace Programming_lab_06
{
    class ShopWithShowcase: Shop
    {
		private int showcase_level_;

		public ShopWithShowcase() : base()
		{
			showcase_level_ = 0;
		}

		public ShopWithShowcase(int showcase_level) : base()
		{
			showcase_level_ = showcase_level;
		}

		public bool investInShowcase(float investment_amount)
		{
			if (Cash >= investment_amount && investment_amount > 0)
			{
				Cash -= investment_amount;
				showcase_level_ = (int)(showcase_level_ / 10 + (investment_amount / 1000) + Math.Log10(investment_amount));
				return true;
			}
			return false;
		}

		int getShowcaseLevel()
		{
			return showcase_level_;
		}

        new void setMargin(int percent)
        {
            Margin = 1 + ((float)(percent) + showcase_level_) / 100;
        }

		//new void setMargin(int percent)
		//{
		//    base.setMargin(percent + showcase_level_);
		//}

		


	}
}

int calc_delay(int level)
{
    if (level != 15)
    {
        return 250000 - (30000 * level);
    }
    else
    {
		return 100000;
    }
}

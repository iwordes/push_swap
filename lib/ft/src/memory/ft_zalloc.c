void	*ft_zalloc(size_t n)
{
	void	*mem;

	NULL_GUARD(mem = malloc(n));
	bzero(mem, n);
	return (mem);
}

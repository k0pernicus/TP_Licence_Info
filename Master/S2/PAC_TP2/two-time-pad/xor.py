def xor(a, b):
	"""
	Fonction permettant de calculer le XOR entre deux chaînes de bytes
	"""
	c = bytearray()
	for x,y in zip(a,b):
		c.append(x ^ y)
	return c

def xor_byte(a, b):
	"""
	Fonction permettant de calculer le XOR entre deux caractères
	"""
	return a ^ b

import sys

def string2bits(s=''):
    return [bin(ord(x))[2:].zfill(8) for x in s]

def bits2string(b=None):
    return ''.join([chr(int(x, 2)) for x in b])

def main():
	fp = open(sys.argv[1], 'r') #Arquivo a ser convertido pra binario
	fp2 = open("/home/nothereboy/Documents/IESB/PD1/Projeto-Urna-Eletronica/Arquivos de teste/BIN/BINCONV10.lz78", 'w') #Arquivo convertido pra binario
	elemento = ""
	if (sys.argv[2] == 'B'):
		for i in fp:
			#for j in i:
			linha = string2bits(i)
			for j in linha:
				#print j
				elemento = elemento+j
				#print elemento
			#print elemento1
			#elemento2 = linha[1]
			#elemento3 = linha[2]
			#print elemento3
			#fp2.write(elemento1+','+elemento3+"\n")
			fp2.write(elemento+'\n')
			elemento = ""
		#b = string2bits(s)
		fp.close()
		fp2.close()
		#print '\nList of Bits:'
		#for x in b:
			#print x
	elif (sys.argv[2] == 'S'):
		s2 = bits2string(b)
		print '\nString:'
		print s2
	else :
		print("[-] Arquivo invalido.\n")

if __name__ == '__main__':
	main()

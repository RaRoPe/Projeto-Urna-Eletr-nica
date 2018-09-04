# -*- coding: utf-8 -*-

fp = open("dados_candidatos_distritais_MS.txt", "r")
fp2 = open("dados_candidatos_MS.txt","w")
fp3 = open("lista_partidos_2018.txt", "r")

for i in fp:
	break

for i in fp:
	numero_partido = 1
	vetor_de_campos = i.split(";")
	
	fp3.seek(0)
	
	for j in fp3:
		#print ("= |" + j.strip("\n") + "| |" + str(vetor_de_campos[5]) + "|")
		if (j.strip("\n") == vetor_de_campos[5]):
			#print ("= |" + j.strip("\n") + "| |" + str(vetor_de_campos[5]) + "|")
			break
		numero_partido += 1
	fp2.write(vetor_de_campos[4]+";"+vetor_de_campos[1]+";"+str(numero_partido)+"\n")
	#raw_input()
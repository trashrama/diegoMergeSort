import random
listaPequena = []
listaMedia = []
listaGrande = []


def percorrerAndGravar(lista):
    f = open("listas.txt", "a")
    for i in range(len(lista)):
        if i == 0:
            f.writelines("{")
        f.writelines(f"{lista[i]}")
        if i != len(lista)-1:
            f.writelines(", ")
        if i == len(lista)-1:
            f.writelines("}\n")


for i in range(10):
    num = random.randint(0, 10)
    listaPequena.append(num)

for i in range(100):
    num = random.randint(0, 1000)
    listaMedia.append(num)


for i in range(1000):
    num = random.randint(0, 10000)
    listaGrande.append(num)


percorrerAndGravar(listaPequena)
percorrerAndGravar(listaMedia)
percorrerAndGravar(listaGrande)

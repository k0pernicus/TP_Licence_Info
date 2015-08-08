class Random:
    """
    Classe permettant de générer un objet Random, permettant (après initialisation avec une graine quelconque) de générer des nombres pseudo-aléatoires comme la fonction rand() du langage C
    """

    def __init__(self):
        self.next = 1

    def srand(self, seed):
        """
        Initialisation de la graine avec 'seed'
        """
        self.next = seed

    def rand(self):
        """
        Génération d'un nombre pseudo-aléatoire
        """
        self.next = self.next * 1103515245 + 12345 % 2**32
        return (self.next // 2**16) % 2**15

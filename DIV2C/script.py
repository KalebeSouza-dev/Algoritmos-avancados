import requests
import random

def pegar_div2_C(qtd=5, min_rating=None, max_rating=None):
    # API problemas
    url_problems = "https://codeforces.com/api/problemset.problems"
    resposta = requests.get(url_problems).json()

    if resposta["status"] != "OK":
        print("Erro ao acessar problemset.problems")
        return
    
    problemas = resposta["result"]["problems"]

    # API contests
    url_contests = "https://codeforces.com/api/contest.list"
    resposta_contests = requests.get(url_contests).json()

    if resposta_contests["status"] != "OK":
        print("Erro ao acessar contest.list")
        return

    contests = resposta_contests["result"]

    # Criar set com IDs de contests Div2
    div2_ids = set()
    for c in contests:
        nome = c["name"]
        if "Div. 2" in nome:
            div2_ids.add(c["id"])

    # Filtrar problemas que são C e pertencem a contests Div2
    div2_C = []
    for p in problemas:
        if p["index"] == "C" and p["contestId"] in div2_ids:
            if "rating" in p:
                rating = p["rating"]

                if min_rating is not None and rating < min_rating:
                    continue
                if max_rating is not None and rating > max_rating:
                    continue

            div2_C.append(p)

    if not div2_C:
        print("Nenhuma questão Div2 C encontrada com esses filtros.")
        return

    # Sorteia questões
    escolhidos = random.sample(div2_C, min(qtd, len(div2_C)))

    # Printar
    for i, problema in enumerate(escolhidos, start=1):
        contest_id = problema["contestId"]
        index = problema["index"]
        nome = problema["name"]
        rating = problema.get("rating", "Sem rating")
        url_problema = f"https://codeforces.com/problemset/problem/{contest_id}/{index}"

        print(f"Questão {i}: {nome}")
        print(f"  Contest: {contest_id} (Div2)")
        print(f"  Rating: {rating}")
        print(f"  Link: {url_problema}\n")


# Exemplo de uso:
pegar_div2_C(qtd=5, min_rating=1400, max_rating=1900)

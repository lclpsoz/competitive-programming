import requests
from time import sleep
from bs4 import BeautifulSoup
import webbrowser

# Coletar e analisar a primeira página
# page = requests.get('https://www.urionlinejudge.com.br/judge/pt/problems/all')

for i in range (1, 4):
    webbrowser.open ("https://www.urionlinejudge.com.br/judge/pt/problems/all?page=" + str (i))
    sleep(1)

soup = BeautifulSoup(page.text, 'html.parser')

print (soup)

# Pegar todo o texto da div BodyText
artist_name_list = soup.find(class_='BodyText')

# Pegar o texto de todas as instâncias da tag <a> dentro da div BodyText
artist_name_list_items = artist_name_list.find_all('a')

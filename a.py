import requests 
URL = 'https://blog.naver.com/yysong96/222451026722' 
response = requests.get(URL) 
print(response.status_code)
print(response.text)

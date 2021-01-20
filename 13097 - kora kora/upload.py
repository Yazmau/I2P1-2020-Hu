import requests
import getpass

url = 'https://acm.cs.nthu.edu.tw/users/login/'
username = input('Username: ')
password = getpass.getpass('Password: ')

session = requests.session()
r = session.get(url)

payload = {
  'username': username,
  'password': password,
  'csrfmiddlewaretoken': session.cookies['csrftoken']
}

headers = {
  'Referer': url,
}

res = session.post(url, headers=headers, data=payload)

if res.status_code == 200:
  print('Login successfully')

problem_id = input('Problem ID: ')
upload_url = f'https://acm.cs.nthu.edu.tw/problem/{problem_id}/testcase/'

headers = {
  'Referer': f'https://acm.cs.nthu.edu.tw/problem/{problem_id}/edit/',
  'X-CSRFToken': session.cookies['csrftoken']
}

testcases = int(input('Number of testcases: '))

for testcase in range(1,testcases + 1):
  file_name = f'./tests/{str(testcase)}'
  print(f'Uploading {file_name}.in, {file_name}.out ...')

  files = {
    't_in': open(f'{file_name}.in', 'rb'),
    't_out': open(f'{file_name}.out', 'rb')
  }

  payload = {
    'time_limit': 1,
    'memory_limit': 32
  }

  res = session.post(upload_url, headers=headers, files=files, data=payload)

  if res.status_code == 200:
    print(f'Upload {file_name}.in, {file_name}.out successfully')

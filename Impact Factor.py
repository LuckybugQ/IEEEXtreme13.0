import json


class data:
    def __init__(self, title, factor):
        self.title = title
        self.factor = factor


n = int(input())
l = list()
while n > 0:
    s = str(input())
    json_data = json.loads(s)
    l.append(json_data)
    n = n - 1
book = l[0]['publications']
book_length = len(book)
titleL = list()
numberL = list()
countL = list()
publicL = list()
for i in range(book_length):
    title = book[i]['publicationTitle']
    titleL.append(title)
    number = int(book[i]['publicationNumber'])
    numberL.append(number)
    counts = book[i]['articleCounts']
    count = 0;
    for j in range(len(counts)):
        year = int(counts[j]['year'])
        if(year==2017 or year==2018):
            count = count + int(counts[j]['articleCount'])
        #print(counts[j]['articleCount'])

    countL.append(count)
    publicL.append(0)

for i in range(len(l) - 1):
    i = i + 1;
    ieee = l[i]['paperCitations']['ieee']
    for j in range(len(ieee)):
        num = int(ieee[j]['publicationNumber'])
        year = int(ieee[j]['year'])
        if (year == 2017 or year == 2018):
            for k in range(book_length):
                if (numberL[k] == num):
                    publicL[k] = publicL[k] + 1
                    break

tmp = []

for i in range(book_length):
    #print(str(publicL[i]) + " " + str(countL[i]))
    factor = float(publicL[i]) / float(countL[i])
    tmp.append(data(titleL[i], factor))
    tmp = sorted(tmp,key=lambda x: x.title)
    tmp = sorted(tmp,key=lambda x: x.factor,reverse=True)

for i in range(len(tmp)):
    print(tmp[i].title + ": " + '%.2f' % tmp[i].factor)

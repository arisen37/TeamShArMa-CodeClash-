from datetime import datetime, timedelta

def get_date_obj(date_str):
    return datetime.strptime(date_str, '%Y-%m-%d')

def get_text_date(date_obj):
    return date_obj.strftime("%Y-%m-%d")

def check(date, y, d, out_dates):
    for i in range(y):
        year_e = date - timedelta(days=i * 365)
        year_i = year_e - timedelta(days=364)

        days_out = 0
        for out_i, out_e in out_dates:
            start = max(year_i, out_i)
            end = min(year_e, out_e)
            if start <= end:
                days_out += (end - start).days + 1

        days_in = 365 - days_out
        if days_in < d:
            return False
    return True

n, y, d = map(int, input().split())
out_dates = []

for _ in range(n):
    start_str, end_str = input().split()
    start = get_date_obj(start_str)
    end = get_date_obj(end_str)
    out_dates.append((start, end))

last_date = out_dates[-1][1]
current_date = last_date

while True:
    if check(current_date, y, d, out_dates):
        print(get_text_date(current_date+timedelta(days=2)))
        break
    current_date += timedelta(days=1)

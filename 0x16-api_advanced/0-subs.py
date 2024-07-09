#!/usr/bin/python3
"""This is 0-subs module
"""
import requests


def number_of_subscribers(subreddit):
    """function that queries the Reddit API
    and returns the number of subscribers
    """
    u_agent = 'Mozilla/5.0'

    headers = {
        'User-Agent': u_agent
    }
    url = f"https://www.reddit.com/r/{subreddit}/about.json"
    res = requests.get(url, headers=headers, allow_redirects=False)

    if res.status_code == 400:
        return -1
    elif res.status_code != 200:
        return 0
    dic = res.json()
    if 'data' not in dic:
        return 0
    if 'subscribers' not in dic.get('data'):
        return 0
    return res.json()['data']['subscribers']


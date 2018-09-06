'''py_function.py - Python source designed to '''
'''demonstrate the use of python embedding'''

def multiply():
    print("test point 1 in py")
    c = 12345*6789
    print ('The result of 12345 x 6789 :', c)
    return c


def get_data():
    import requests
    weather_url="http://dataservice.accuweather.com/currentconditions/v1/206690?apikey=oFGptohDvJ6AtTgijcbjPLiqBXeWOol0&details=false"
    weather_data=requests.get(weather_url).json()
    print('weather data: ',weather_data)
    return weather_data

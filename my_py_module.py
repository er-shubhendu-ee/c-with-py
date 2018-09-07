def multiply(a,b):
    print("Will compute",a, "times",b)
    c = 0
    for i in range(0, a):
        c = c + b
    return c

def weather_data():
    website="accuweather.com"
    print("Aquuiring data from www.",website)
    if ("accuweather" in website):
        import requests
        url="http://dataservice.accuweather.com/currentconditions/v1/206690?apikey=oFGptohDvJ6AtTgijcbjPLiqBXeWOol0&details=false"
        weather_data=requests.get(url).json()
        print(weather_data)
        return 1	
    else:
        return 0
    

# Plan is to retrieve data from an open API and parse it in some way

import requests
import json

def main():

    # Retrieve cat images
    response = requests.get("https://api.thecatapi.com/v1/images/search", headers={
        'x-api-key': 'live_hciGEzNbMbvNyfxPZ7c50GhGwAQDscMgNvSi0x8cAXzMHu517q38je3S9capT0by'
    })
    if response.status_code == 200:
        print(f"Status Code: {response.status_code}")
        json_data = response.json()
        print(json.dumps(json_data, indent=4))
        if (len(json_data) > 0):
            url = json_data[0]["url"]
            filename = url.split('/')[-1]
            print(f"URL: {url}")

            # Download image from url
            img_data = requests.get(url).content # Get the image bytes
            with open(f'stripe/prep/cats/{filename}', 'wb') as f:
                f.write(img_data)

    else:
        print("Failed to retrieve cat!")

    # Retrieve simple weather data
    # city_name = "Dublin"
    # country_code = ""
    # response = requests.get("http://api.openweathermap.org/data/2.5/forecast",
    #     params={
    #         'q': f"{city_name},{country_code}",
    #         'appid': "43f9a83de74ca1a397fce7781fed2eeb"
    #     })
    # print(response.headers)
    # print(response.text)
    # json_data = response.json()
    # print(json_data)

if __name__ == "__main__":
    main()
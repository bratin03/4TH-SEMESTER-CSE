from PIL import Image
import requests
from io import BytesIO

class Download(object):
    '''
        A class for helping in downloading the required images from the given URL to the specified path
    '''

    def __call__(self, path, url):
        '''
            Arguments:
            path: download path with the file name
            url: required image URL
        '''
        response = requests.get(url)
        img = Image.open(BytesIO(response.content))
        img.save(path)

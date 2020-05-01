import PIL
from PIL import Image

#Remember changing the file name
img = Image.open('image.jpg')
WIDTH, HEIGHT = img.size
img = img.resize((WIDTH,HEIGHT), PIL.Image.ANTIALIAS)
img.save('resized.jpg')
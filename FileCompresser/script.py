import zlib, base64

ffile = open('D:\Proyectos\hola\MiniProjects\FileCompresser\iest.txt', 'r')
text  = ffile.read()
ffile.close()

code = base64.b64encode(zlib.compress(text.encode('utf-8'),9))
code = code.decode('utf-8')

f = open('compressed.txt', 'w')
f.write(code)
f.close()
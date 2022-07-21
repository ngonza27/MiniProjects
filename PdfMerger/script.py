from dataclasses import field
import PyPDF2 as pdf2
import os

merger = pdf2.PdfFileMerger()

for file in os.listdir(os.curdir):
  print(file)
  if file.endswith(".pdf"):
    merger.append(file) 
merger.write("combined.pdf")
  
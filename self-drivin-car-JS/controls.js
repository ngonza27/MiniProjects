class Controls {
  constructor(type) {
    this.forward = false;
    this.left = false;
    this.right = false;
  
    switch(type){
      case "KEYS":
        this.#addKeyboardListeners()
        break
      case "DUMMY":
        this.forward=true
        break
    }
  }

  #addKeyboardListeners(){
    document.onkeydown=(event)=>{
      switch(event.key){
        case "ArrowLeft":
          this.left=true;
          break;
        case "ArrowRight":
          this.right=true;
          break;
        case "ArrowUp":
          this.forward=true;
          break;
      }
    }
    document.onkeyup=(event)=>{
      switch(event.key){
        case "ArrowLeft":
          this.left=false;
          break;
        case "ArrowRight":
          this.right=false;
          break;
        case "ArrowUp":
          this.forward=false;
          break;
      }
    }
  }
  
}
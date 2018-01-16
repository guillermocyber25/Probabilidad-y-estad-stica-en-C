package com.genbetadev;
 
public class Impresora {
 
 
    private String tipoDocumento;
    private String hoja;
    private boolean color;
    private String texto;
     
     
    public String getTipoDocumento() {
        return tipoDocumento;
    }
    public void setTipoDocumento(String tipoDocumento) {
        this.tipoDocumento = tipoDocumento;
    }
    public String getHoja() {
        return hoja;
    }
    public void setHoja(String hoja) {
        this.hoja = hoja;
    }
    public boolean isColor() {
        return color;
    }
    public void setColor(boolean color) {
        this.color = color;
    }
    public String getTexto() {
        return texto;
    }
    public void setTexto(String texto) {
        this.texto = texto;
    }
     
    public void imprimirDocumento() {
         
        System.out.println("imprimiendo:"+ texto+ ",color:"
        + color+",tipo:"+tipoDocumento+",hoja :"+hoja);
    }
}

///cliente

package com.genbetadev;
 
public class PrincipalCliente {
 
    public static void main(String[] args) {
         
         
        Impresora i = new Impresora();
        i.setHoja("a4");
        i.setColor(true);
        i.setTipoDocumento("pdf");
        i.setTexto("texto 1");
        i.imprimirDocumento();
         
        Impresora i2 = new Impresora();
        i2.setHoja("a4");
        i2.setColor(true);
        i2.setTipoDocumento("pdf");
        i2.setTexto("texto 2");
        i2.imprimirDocumento();
         
        Impresora i3 = new Impresora();
        i3.setHoja("a3");
        i3.setColor(false);
        i3.setTipoDocumento("excel");
        i3.setTexto("texto 3");
        i3.imprimirDocumento();
    }
 
}

// fachada
package com.genbetadev;
 
public class FachadaImpresoraNormal {
 
    Impresora impresora;
     
     
    public FachadaImpresoraNormal(String texto) {
        super();
        impresora= new Impresora();
        impresora.setColor(true);
        impresora.setHoja("A4");
        impresora.setTipoDocumento("PDF");
        impresora.setTexto(texto);
    }
 
 
    public void imprimir() {
         
        impresora.imprimirDocumento();
    }
     
}

package com.genbetadev;
 
public class PrincipalCliente2 {
 
    public static void main(String[] args) {
         
         
        FachadaImpresoraNormal fachada1= new FachadaImpresoraNormal("texto1");
        fachada1.imprimir();
         
        FachadaImpresoraNormal fachada2= new FachadaImpresoraNormal("texto2");
        fachada2.imprimir();
         
         
        Impresora i3 = new Impresora();
        i3.setHoja("a4");
        i3.setColor(true);
        i3.setTipoDocumento("excel");
        i3.setTexto("texto 3");
        i3.imprimirDocumento();
    }
 
}
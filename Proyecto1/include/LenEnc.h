#ifndef __LEN_ENC__
#define __LEN_ENC__

/**
 * @class Clase encargada de realizar las operaciones necesarias para la compresión utilizando el algoritmo RLE
 * */
class LenEnc{
 
  public:
      /**
       * @brief Constructor de la clase
       */
    LenEnc();
      /**
       * @brief Destructor de la clase
       */
    ~LenEnc();
    
    /**
     * @brief Método que comprime un archivo de texto utilizando RLE
     * @param filename: nombre del archivo a comprimir, no retorna pero si escribe un archivo cuyo nombre es
     * filename + ".rlen"
     * */
    void encoding(const std::string &filename);
    /**
     * @brief Método que descomprime un archivo rlen utilizando RLE
     * @param filename: nombre del archivo con formato .rlen, no retorna pero si escribe un archivo cuyo nombre es
     * filename + ".rlen_uncompressed"
     * */
    void decoding(const std::string &filename);

};

#endif /* __LEN_ENC__ */

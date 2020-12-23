/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package webscrap;

/**
 *
 * @author AntKerf
 */
public class MyUtil {

    // контейнер пара
    public static class Pair<U, V> {

        private final U first;
        private final V second;

        //Конструктор с параметрами 
        public Pair(U one, V two) {
            this.first = one;
            this.second = two;
        }

        //Конструктор копирования
        public Pair(Pair<U, V> toCopy) {
            this.first = toCopy.first;
            this.second = toCopy.second;
        }

        public U getFirst() {
            return this.first;
        }

        public V getSecond() {
            return this.second;
        }

    }
}

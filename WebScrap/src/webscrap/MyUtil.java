package webscrap;

/**
 *
 * @author AntKerf
 */
public class MyUtil {

    // контейнер пара
    public static class Pair<U, V> {

        private U first;
        private V second;

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

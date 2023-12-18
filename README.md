<details open>
<summary><span style="color:tomato;font-size:16px">HTTP REQUESTS</span></summary>
<details open>
<summary><span style="color:tomato;font-size:12px">Захват заголовка веб-страницы</span></summary>

Запросите с сервера HTML-страницу. 

Для этого изучите документацию о запросах, поддерживаемых сервисом httpbin.org/html. 

Найдите там запрос, который выдаёт именно HTML-страницу. 

Затем сделайте запрос, явным образом используя заголовок accept: text/html. 

В полученном ответе найдите заголовок статьи и выведите его в консоль.

---

Заголовок статьи размещается между HTML-тегами h1.

Для доступа к тексту ответа вам потребуется метод text класса `cpr::Response`. 

Для поиска по тексту нужных HTML-тегов лучше использовать метод `find`.

</details>

<details open>
<summary><span style="color:tomato;font-size:12px">INFO</span></summary>

[//]: # (<a href="" style="margin-left:16px">REF</a>)

</details>
</details>
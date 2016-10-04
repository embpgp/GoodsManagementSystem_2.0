/* HTML document is loaded. DOM is ready.
-------------------------------------------*/
$(function(){
    $('#tab1 tbody').load('index.php?type=inventory');
    $('#tab2 tbody').load('index.php?type=record');
    $('#cate').load('index.php?type=cate');
    $("#tab1 button").click(function() {
        $('#tab1 tbody').load('index.php?type=inventory');
    });
    
    $("#tab2 button").click(function() {
        var url = 'index.php?type=record&value='+$('#cate').val();
        $('#tab2 tbody').load(url);
    });
    $("#cate").change(function() {
        var url = 'index.php?type=record&value='+$('#cate').val();
        //alert(url);
        $('#tab2 tbody').load(url);
    });


});


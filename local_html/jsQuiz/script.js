$("document").ready(() => {

    $('.striptable tr').each(function(){
        $(this).find('td').each(function(){
            $(this).click(() => {
                $('.striptable #selected').attr('id', 'notselected')
                $(this).attr('id', 'selected');
                changeAllColor($(this).attr('class'));
            });
        })
    })

    $('.maintable tr').each(function(){
        $(this).find('td').each(function(){
            $(this).click(() => {
                var color = $('.striptable #selected').attr('class')
                var id  = $(this).attr('id');
                var row = parseInt(id.substring(0,2));
                var col = parseInt(id.substring(2,4));

                if ($(this).attr('class')) {
                    $(this).removeAttr('class')
                } else {
                    $(this).attr('class', color);
                }

                var above = '#'+getabove(row,col);
                var below = '#'+getbelow(row,col);
                var right = '#'+getright(row,col);
                var left = '#'+getleft(row,col);

                changeColor('#'+id,above, color);
                changeColor('#'+id,below, color);
                changeColor('#'+id,right, color);
                changeColor('#'+id,left,  color);
            });
        })
    })

    function getabove(row, col) {
        if (row == 0) {
            return "00" + addzero(col);
        } else {
            return addzero(row-1) + addzero(col);
        }
    }
    function getbelow(row, col) {
        if (row == 19) {
            return "19" + addzero(col);
        } else {
            return addzero(row+1) + addzero(col);
        }
    }
    function getleft(row, col) {
        if (col == 0) {
            return addzero(row) + "00";
        } else {
            return addzero(row) + addzero(col-1);
        }
    }
    function getright(row, col) {
        if (col == 19) {
            return addzero(row) + "19";
        } else {
            return addzero(row) + addzero(col+1);
        }
    }
    function addzero(x) {
        if (x < 10) {
            return "0" + x.toString();
        } else {
            return x.toString();
        }
    }
    function changeColor(cur, loc, color) {
        if(cur !== loc) {
            if ($(loc).attr('class')) {
                $(loc).removeAttr('class')
            } else {
                $(loc).attr('class', color);
            }
        }
    }
    function changeAllColor(color) {
        $('.maintable tr').each(function(){
            $(this).find('td').each(function(){
                if ($(this).attr('class')) {
                    $(this).attr('class',color);
                } 
            })
        })
    }
});

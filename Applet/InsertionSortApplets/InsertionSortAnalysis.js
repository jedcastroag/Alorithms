const MAX_CASES = 1001;

// Necesary Global Variables for compute the distributions
let comparation_total, time_total, /*Acumulative variables for the nuber of comparations
    between the elements of the array and the executed lines*/
    permut, //Number of permutations variable
    n = 4,//Initial congig
    comparation_prob, time_prob, // probabilities arrays, initialized in start function
    comparation_cases = new Array(MAX_CASES), time_cases = new Array(MAX_CASES);

//Compute the number of comparations between elements 
function isortCompSteps(aux) {
    let steps = 0,
        i = 0,
        j, k,
        v = new Array(aux.length);
    for (let num of aux) {
        v[i++] = num;
    }
    for (i = 1; i < v.length; ++i) {
        x = v[i];
        j = i - 1;
        while (j > -1 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
            steps++;
        }
        if (j != -1) {
            steps++;
        }
        v[j + 1] = x;
    }
    return steps;
}


//Compute the number of executed lines 
function isortTimeSteps(aux) {
    let steps = 0,
        i = 0,
        j,
        v = new Array(aux.length);
    for (let num of aux) {
        v[i++] = num;
    }
    for (i = 1; i < v.length; ++i) {
        x = v[i];
        j = i - 1;
        while (j > -1 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
            steps+=3;
        }
        steps++;
        v[j + 1] = x;
        steps += 4;
    }
    return steps;
}

function swap(v, i, j) {
    let x = v[i];
    v[i] = v[j];
    v[j] = x;
}

//build the permutations of the array 'v'
function perm(v, i, n) {
    let j = comp_steps = 0;
    if (i == n) {

        permut++;
        comparation_steps = isortCompSteps(v);
        comparation_total += comparation_steps;
        comparation_cases[comparation_steps]++;

        time_steps = isortTimeSteps(v);
        time_total += time_steps;
        time_cases[time_steps]++;
    } else {
        for (j = i; j < n; j++) {
            swap(v, i, j);
            perm(v, i + 1, n);
            swap(v, i, j);
        }
    }
}

function createElement(element_tag = "", attributes = {}) {
    let element = document.createElement(element_tag);
    let attributes_keys = Object.keys(attributes);
    attributes_keys.map((key) => {element.setAttribute(key, attributes[key])});
    return element;
}

//Add the necesary elements to the DOM for rendering the results
function init() {
    
    let view = document.getElementById('view-frame');
    view.className = " row view-frame justify-content-center";

    let input_div = createElement('div',{id: 'input_div',class: 'frame container-fluid'});
    input_div.appendChild(document.createTextNode('Enter n: '))
    input_div.appendChild(createElement('input', {
        type: 'number',
        min: '1',
        defaultvalue: n.toString(),
        placeholder: n.toString(),
        id: 'number_input',
        class:'number_input'}));    
    view.appendChild(input_div);

    function createFrame(id_frame) {
        let frame = createElement('div', {class:'frame col-md-6 col-12 ', id_frame:id_frame});
        let content_container = createElement('div', {class: 'container-fluid', id: id_frame + '_content_container'});
        let content = createElement('div', {class: 'row justify-content-center'});
        let graphElemClass = "col-sm-8 col-12 no-gutters";
        let distributionClass = "col-sm-4 col-12";

        let graphElem = createElement('div', {id: id_frame + '_graphElem', class: 'graphElem', align: 'center', class: graphElemClass});
        let distribution = createElement('div', {id: id_frame + '_distribution', class: distributionClass + " distribution"});
        let graphic = createElement('div', {id: id_frame + '_graphic', class: 'graphic'});
        let info = createElement('div', {id: id_frame + '_info', class: 'info'});

        number_input.oninput = function () {
            restart();
        };
    
        info.appendChild(document.createTextNode('Number of Permutations: '));
        info.appendChild(createElement('label', {id: id_frame + '_n_perm_label'}));
        info.appendChild(createElement('br'));
        info.appendChild(document.createTextNode('Average of Steps: '));
        info.appendChild(createElement('label', {id: id_frame + '_a_n_steps_label'}));
        info.appendChild(createElement('br'));
    
        distribution.appendChild(createElement('label').appendChild(document.createTextNode('Cases Probability')));
        distribution.appendChild(createElement('ul', {type: 'none', id: id_frame + '_dist-list'}));

        graphElem.appendChild(graphic);
        graphElem.appendChild(info);    
    
        content.appendChild(graphElem);
        content.appendChild(distribution);

        content_container.appendChild(content);

        frame.appendChild(content_container);

        return frame;
    }

    time_frame = createFrame('time_frame');
    comparations_frame = createFrame('comparation_frame');

    view.appendChild(time_frame);
    view.appendChild(comparations_frame);

}

function restart() {
    n = document.getElementById('number_input').value;
    start();
}

function plot(x, y, prob, total, id_frame, title) {
    let graph = document.getElementById(id_frame + '_graphic');

    Plotly.newPlot(graph, [{
        x: x,
        y: y,
        type: 'bar',
    }], {
        title: title + ' Distribution',
        font: {
            size: 16
        },
    }, {
        responsive: true
    });

    let n_perm_label = document.getElementById(id_frame + '_n_perm_label');
    let a_n_steps_label = document.getElementById(id_frame + '_a_n_steps_label');

    while (n_perm_label.firstChild) {
        n_perm_label.removeChild(n_perm_label.firstChild);
    }

    while (a_n_steps_label.firstChild) {
        a_n_steps_label.removeChild(a_n_steps_label.firstChild);
    }

    n_perm_label.appendChild(document.createTextNode(permut.toString()));
    a_n_steps_label.appendChild(document.createTextNode((total/permut).toFixed(6).toString()));

    let dist_list = document.getElementById(id_frame + '_dist-list');
    let li;

    while (dist_list.firstChild) {
        dist_list.removeChild(dist_list.firstChild);
    }
    for (step of x) {
        li = createElement('ĺi');
        li.appendChild(document.createTextNode(step + " => " + prob[step].toFixed(6)));
        dist_list.appendChild(li);
        dist_list.appendChild(createElement('br'));
    }
}

function start() {
    let v = [],
        comparation_x = [],
        time_x = [], 
        comparation_y,
        time_y;
    let k;
    comparation_total = 0;
    time_total = 0;
    permut = 0;
    comparation_prob = [];
    comparation_cases = [];
    time_prob = [];
    time_cases = [];
    for (k = 0; k < MAX_CASES; k++) {
        comparation_prob[k] = 0.0;
        comparation_cases[k] = 0;
        time_prob[k] = 0.0;
        time_cases[k] = 0;
    }

    for (k = 0; k < n; k++) {
        v[k] = k + 1;
    }
    perm(v, 0, n);
    for (k = 0; k < MAX_CASES; k++) {
        comparation_prob[k] = comparation_cases[k] / permut;
        time_prob[k] = time_cases[k] / permut;
        if (comparation_cases[k] > 0) {
            comparation_x.push(k);
        }
        if (time_cases[k] > 0) {
            time_x.push(k);
        }
    }

    comparation_y = comparation_prob.filter(item => item > 0);
    time_y = time_prob.filter(item => item > 0);
    
    plot(comparation_x, comparation_y, comparation_prob, comparation_total, 'comparation_frame', 'Comparations');
    plot(time_x, time_y, time_prob, time_total, 'time_frame', 'Time');

}

init();
start();

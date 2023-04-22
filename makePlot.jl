using Plotly
function makePlot(numOfPlots, plotStep, solutionMatrix, dataVec, intervalVec)
    a = dataVec[1]
    L = dataVec[2]
    timeEnd = dataVec[3]
    numOfXIntervals = Int(intervalVec[1])
    numOfTIntervals = Int(intervalVec[2])

    h = L / numOfXIntervals
    τ = timeEnd / numOfTIntervals    
    
    titleText = "a = $a,      x ∈ [0, $L], t ∈ [0, $timeEnd]      h = $h, τ = $τ"
    
    layout = Layout(
        font_family = "Time New Roman",
        font_color = "black",
        title = attr(
            paper_bgcolor = "red",
            text = titleText,
            font_family = "Times New Roman",
            font_color = "black",
            font_size = 20,
            autosize = false,
        ),
        legend = attr(
            font = attr(
                size = 16
            ) 
        ),
        paper_bgcolor = "white",
        plot_bgcolor = "white",
        coloraxis = attr(
        outlinecolor = "black"  
        ),
        height = 600,
        width = 1000,
        xaxis = attr(
            color = "black",
            gridcolor = "black",
            gridwidth = 1,
            zerolinecolor = "black",
            zerolinewidth = 3,
            linecolor = "black",
            linewidth = 3,
            tickfont = attr(
                size = 15
            ),
            title = attr(
                text = "x",
                font_family = "Times New Roman",
                font_color = "black",
                font_size = 20,
            )
        ),
        yaxis = attr(
            gridcolor = "black",
            exponentformat = "power",
            gridwidth = 1,
            zerolinecolor = "black",
            tickfont = attr(
                size = 15
            ),
            title = attr(
                text = "T",
                font_family = "Times New Roman",
                font_color = "black",
                font_size = 20,
            )
        )
    );
    lineAttr = attr(
        width = 2
    );
    markerAttr = attr(
        showline = true, 
        line_width = 1
    )
    pl = plot(
        [scatter(name = "$((k - 1) * τ)", x = [i * h for i in 0 : numOfXIntervals], y = [solutionMatrix[k, i] for i in 1 : numOfXIntervals + 1], mode = "lines+markers", line = lineAttr, marker = markerAttr)
        for k in 1 : plotStep : numOfPlots],
    layout
    )
    return pl
end
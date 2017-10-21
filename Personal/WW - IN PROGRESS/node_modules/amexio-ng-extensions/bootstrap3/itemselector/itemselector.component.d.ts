import { AfterViewInit, OnInit } from '@angular/core';
import { ItemSelectorService } from "./itemselector.service";
export declare class ItemSelectorComponent implements OnInit, AfterViewInit {
    private itemSelectorService;
    height: any;
    httpUrl: string;
    dataReader: string;
    httpMethod: string;
    ItemSelectBindData: any;
    displayField: string;
    valueField: string;
    availableRecords: any;
    selectedRecords: any;
    availableData: any[];
    selectedData: any[];
    switchingObject: any;
    objectIndex: any;
    constructor(itemSelectorService: ItemSelectorService);
    ngOnInit(): void;
    ngAfterViewInit(): void;
    setStyles(): {
        'position': string;
        'height': any;
    };
    setData(httpResponse: any): void;
    itemCkick(data: any, index: any): void;
    rightSwitch(): void;
    leftSwitch(): void;
    upSwitch(): void;
    downSwitch(): void;
    moveTop(): void;
    moveDown(): void;
    dataEmitter(): void;
}
